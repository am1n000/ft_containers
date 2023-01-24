
namespace ft
{
    // enable_if
    template<bool Cond, class T = void> // if false
    struct enable_if {};

    template<class T> // specialization
    struct enable_if<true, T> // if true
    {
        typedef T type;
    };


    // ft::is_integral
    template <class T, T v>
    struct integral_constant
    {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T,v> type;
        operator T()
        { return v; }
    };

    template<typename T>
    struct remove_const
    {
        typedef T type;
    };
    template<typename T>
    struct remove_const<const T>
    {
        typedef T type;
    };

    template<typename T>
    struct remove_volatile
    {
        typedef T type;
    };
    template<typename T>
    struct remove_volatile<volatile T>
    {
        typedef T type;
    };

    template<typename T>
    struct remove_cv
    {
        typedef typename remove_volatile<typename remove_const<T>::type>::type type;
    };

    template <class T>
    struct is_integral_base : integral_constant<bool, false> {};
    template <> // this is a specialisation
    struct is_integral_base<bool> : integral_constant<bool, true> {}; // <bool> to indicate that this specialization is for type bool
    template <> 
    struct is_integral_base<char> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<signed char> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<short int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<wchar_t> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<char16_t> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<long int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<long long int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<unsigned char> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<unsigned short int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<unsigned int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<unsigned long int> : integral_constant<bool, true> {};
    template <> 
    struct is_integral_base<unsigned long long int> : integral_constant<bool, true> {};


    template <typename T> 
    struct is_integral : is_integral_base<typename remove_cv<T>::type > {};
};