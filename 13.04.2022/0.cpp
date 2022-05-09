#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>


namespace mine
{
    template <size_t i, typename T>
    struct _leaf
    {
        T item;
        _leaf(const T& item)
        {
            this->item = item;
        }
        _leaf(T&& item)
        {
            this->item = std::move(item);
        }
    };

    //base case (empty tuple)
    template <size_t i, typename... T>
    struct _tuple_impl {};

    //recursive case
    template<size_t i, typename Head, typename... Tail>
    struct _tuple_impl<i, Head, Tail...> : _leaf<i, typename std::remove_reference_t<Head>>, _tuple_impl<i + 1, Tail...>
    {
        template<typename head, typename... tail>
        _tuple_impl(head&& h, tail&&... t) : _leaf<i, typename std::remove_reference_t<head>>(h), _tuple_impl<i + 1, Tail...>(std::forward<tail>(t)...) {}
    };

    //non-const version
    template<size_t i, typename Head, typename... Tail>
    Head& get(_tuple_impl<i, Head, Tail...>& t)
    {
        return t._leaf<i, Head>::item;
    }

    //const version
    template<size_t i, typename Head, typename... Tail>
    Head get(const _tuple_impl<i, Head, Tail...>& t)
    {
        return t._leaf<i, Head>::item;
    }

    template<typename... Tail>
    struct tuple : _tuple_impl<0, Tail...>
    {
        template<typename... tail>
        tuple(tail&&... args) : _tuple_impl<0, Tail...>(std::forward<tail>(args)...) {};

        bool operator<(const tuple<Tail...>& t) const
        {
            return less_tuples<0>(*this, t);
        }

        template<size_t i>
        bool less_tuples(const tuple<Tail...>& t1, const tuple<Tail...>& t2) const
        {
            if (i + 1 == sizeof...(Tail)) return get<i>(t1) < get<i>(t2);
            else if (get<i>(t1) == get<i>(t2)) return less_tuples<i + 1>(t1, t2);
            else return get<i>(t1) < get<i>(t2);
        }

        template<>
        bool less_tuples<sizeof...(Tail)>(const tuple<Tail...>& t1, const tuple<Tail...>& t2) const
        {
            return false;
        }
    };


    template<typename... Tail>
    tuple<Tail...> make_tuple(Tail&&... t)
    {
        return tuple<Tail...>{std::forward<Tail>(t)...};
    }
}

struct student
{
    std::string f, i, o;
    int year;
    int a[5];
    double am()
    {
        int sum = 0;
        for (int i = 0; i < 5; ++i)
            sum += a[i];
        return sum / 5.0;
    }
};

std::istream& operator>>(std::istream& in, student& obj)
{
    in >> obj.f >> obj.i >> obj.o >> obj.year;
    for (int i = 0; i < 5; ++i)
        in >> obj.a[i];
    return in;

}

std::ostream& operator<<(std::ostream& out, const student& obj)
{
    out << obj.f << ' ' << obj.i << ' ' << obj.o << ' ' << obj.year << ' ';
    for (int i = 0; i < 5; ++i)
        out << obj.a[i] << ' ';
    return out;
}





int main()
{
    int n;
    std::cin >> n;
    std::vector<student> a(n);
    for (student& x : a)
        std::cin >> x;
    //student a{ "Vanya", "Rodin", "Sergeevich", 2003, 2, 2, 2, 2, 2};
    //student b{ "NeVanya", "Rodin", "Sergeevich", 2004, 5, 5, 5, 5, 5 };
    auto cmp = [](student a, student b)
    {
        auto t1 = mine::make_tuple(!a.am(), !a.year, a.f, a.i, a.o), t2 = mine::make_tuple(!b.am(), !b.year, b.f, b.i, b.o);
        return t1 < t2;
    };
    std::sort(a.begin(), a.end(), cmp);
    for (student& x : a)
        std::cout << x;
}

