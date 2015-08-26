
#pragma once

#include <initializer_list>
#include <algorithm>
#include <functional>
#include <array>
#include <sstream>

template <class T, std::size_t N>
class Array
{
public:

    typedef typename std::array<T, N>::value_type
        value_type;
    typedef typename std::array<T, N>::size_type
        size_type;
    typedef typename std::array<T, N>::difference_type
        difference_type;
    typedef typename std::array<T, N>::reference
        reference;
    typedef typename std::array<T, N>::const_reference
        const_reference;
    typedef typename std::array<T, N>::pointer
        pointer;
    typedef typename std::array<T, N>::const_pointer
        const_pointer;
    typedef typename std::array<T, N>::iterator
        iterator;
    typedef typename std::array<T, N>::const_iterator
        const_iterator;
    typedef typename std::array<T, N>::reverse_iterator
        reverse_iterator;
    typedef typename std::array<T, N>::const_reverse_iterator
        const_reverse_iterator;

    std::array<T, N> buffer;

    virtual ~Array ( ) { };

    Array &operator= ( Array other )
    {
        this->buffer = other.buffer;
        return *this;
    }

    Array &operator= ( T other )
    {
        this->buffer.fill(other);
        return *this;
    }

    Array &operator= ( std::initializer_list<T> list )
    {
        std::copy(
            std::begin(list)
        ,   std::end(list)
        ,   std::begin(this->buffer)
        );
        return *this;
    }

    std::array<T, N> operator* ( ) const
    {
        return this->buffer;
    }

    Array operator+ ( Array other ) const
    {
        Array array;
        array = *this;
        array += other;
        return array;
    }

    template <class t_other>
    Array operator+ ( t_other other ) const
    {
        Array array;
        array = *this;
        array += other;
        return array;
    }

    Array &operator+= ( Array other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(other.buffer)
        ,   std::begin(this->buffer)
        ,   std::plus<T>()
        );
        return *this;
    }

    template <class t_other>
    Array &operator+= ( t_other other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return v + other;}
        );
        return *this;
    }

    Array operator- ( Array other ) const
    {
        Array array;
        array = *this;
        array -= other;
        return array;
    }

    template <class t_other>
    Array operator- ( t_other other ) const
    {
        Array array;
        array = *this;
        array -= other;
        return array;
    }

    Array &operator-= ( Array other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(other.buffer)
        ,   std::begin(this->buffer)
        ,   std::minus<T>()
        );
        return *this;
    }

    template <class t_other>
    Array &operator-= ( t_other other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return v - other;}
        );
        return *this;
    }

    Array operator* ( Array other ) const
    {
        Array array;
        array = *this;
        array *= other;
        return array;
    }

    template <class t_other>
    Array operator* ( t_other other ) const
    {
        Array array;
        array = *this;
        array *= other;
        return array;
    }

    Array &operator*= ( Array other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(other.buffer)
        ,   std::begin(this->buffer)
        ,   std::multiplies<T>()
        );
        return *this;
    }

    template <class t_other>
    Array &operator*= ( t_other other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return v * other;}
        );
        return *this;
    }

    Array operator/ ( Array other ) const
    {
        Array array;
        array = *this;
        array /= other;
        return array;
    }

    template <class t_other>
    Array operator/ ( t_other other ) const
    {
        Array array;
        array = *this;
        array /= other;
        return array;
    }

    Array &operator/= ( Array other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(other.buffer)
        ,   std::begin(this->buffer)
        ,   std::divides<T>()
        );
        return *this;
    }

    template <class t_other>
    Array &operator/= ( t_other other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return v / other;}
        );
        return *this;
    }

    Array operator% ( Array other ) const
    {
        Array array;
        array = *this;
        array %= other;
        return array;
    }

    template <class t_other>
    Array operator% ( t_other other ) const
    {
        Array array;
        array = *this;
        array %= other;
        return array;
    }

    Array &operator%= ( Array other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(other.buffer)
        ,   std::begin(this->buffer)
        ,   std::modulus<T>()
        );
        return *this;
    }

    template <class t_other>
    Array &operator%= ( t_other other )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return v % other;}
        );
        return *this;
    }

    Array operator- ( ) const
    {
        Array array;
        array = *this;
        std::transform(
            std::begin(array->buffer)
        ,   std::end(array->buffer)
        ,   std::begin(array->buffer)
        ,   std::negate<T>()
        );
        return array;
    }

    Array &operator++ ( )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return ++v;}
        );
        return *this;
    }

    Array &operator++ ( int )
    {
        Array array;
        array.buffer = this->buffer;
        ++*this;
        return array;
    }

    Array &operator-- ( )
    {
        std::transform(
            std::begin(this->buffer)
        ,   std::end(this->buffer)
        ,   std::begin(this->buffer)
        ,   [&](T v)->T{return --v;}
        );
        return *this;
    }

    Array &operator-- ( int )
    {
        Array array;
        array.buffer = this->buffer;
        --*this;
        return array;
    }

    bool operator== ( Array other ) const
    {
        return this->buffer == other.buffer;
    }

    bool operator!= ( Array other ) const
    {
        return this->buffer != other.buffer;
    }

    bool operator< ( Array other ) const
    {
        return this->buffer < other.buffer;
    }

    bool operator<= ( Array other ) const
    {
        return this->buffer <= other.buffer;
    }

    bool operator> ( Array other ) const
    {
        return this->buffer > other.buffer;
    }

    bool operator>= ( Array other ) const
    {
        return this->buffer >= other.buffer;
    }

    bool operator! ( ) const
    {
        typename std::array<T, N>::const_iterator it;
        for (it = std::begin(this->buffer); it != std::end(this->buffer); ++it)
        {
            if (*it)
            {
                return false;
            }
        }
        return true;
    }

    template <class t_cast>
    Array<t_cast, N> cast ( ) {
        return this->cast_static<t_cast>();
    }

    template <class t_cast>
    Array<t_cast, N> cast_static ( )
    {
        Array<t_cast, N> array;
        unsigned int i;
        for (i = 0; i < N; ++i)
        {
            array.buffer[i] = static_cast<t_cast>(this->buffer[i]);
        }
        return array;
    }

    template <class t_cast>
    Array<t_cast, N> cast_dynamic ( )
    {
        Array<t_cast, N> array;
        unsigned int i;
        for (i = 0; i < N; ++i)
        {
            array.buffer[i] = dynamic_cast<t_cast>(this->buffer[i]);
        }
        return array;
    }

    template <class t_cast>
    Array<t_cast, N> reinterpret ( )
    {
        Array<t_cast, N> array;
        unsigned int i;
        for (i = 0; i < N; ++i)
        {
            array.buffer[i] = reinterpret_cast<t_cast>(this->buffer[i]);
        }
        return array;
    }

    std::string join ( std::string sep = "," ) const
    {
        std::stringstream stream;
        typename std::array<T, N>::const_iterator it;
        stream << *std::begin(this->buffer);
        for (it = std::begin(this->buffer) + 1; it != std::end(this->buffer); ++it)
        {
            stream << sep << *it;
        }
        return stream.str();
    }

    T *data ( )
    {
        return this->buffer.data();
    }

    T at (unsigned int i)
    {
        return this->buffer.at(i);
    }

    T front ( )
    {
        return this->buffer.front();
    }

    T back ( )
    {
        return this->buffer.back();
    }

    void fill ( T other )
    {
        this->buffer.fill(other);
    }

    void swap ( Array other )
    {
        this->buffer.swap(other.buffer);
    }

    void swap ( std::array<T, N> other )
    {
        this->buffer.swap(other);
    }

    bool empty ( )
    {
        return this->buffer.empty();
    }

    bool size ( )
    {
        return this->buffer.size();
    }

    bool max_size ( )
    {
        return this->buffer.max_size();
    }

    iterator begin ( )
    {
        return this->buffer.begin();
    }

    const_iterator begin ( ) const
    {
        return this->buffer.begin();
    }

    const_iterator cbegin ( ) const
    {
        return this->buffer.cbegin();
    }

    iterator end ( )
    {
        return this->buffer.end();
    }

    const_iterator end ( ) const
    {
        return this->buffer.end();
    }

    const_iterator cend ( ) const
    {
        return this->buffer.cend();
    }

    reverse_iterator rbegin ( )
    {
        return this->buffer.rbegin();
    }

    const_reverse_iterator rbegin ( ) const
    {
        return this->buffer.rbegin();
    }

    const_reverse_iterator crbegin ( ) const
    {
        return this->buffer.crbegin();
    }

    reverse_iterator rend ( )
    {
        return this->buffer.rend();
    }

    const_reverse_iterator rend ( ) const
    {
        return this->buffer.rend();
    }

    const_reverse_iterator crend ( ) const
    {
        return this->buffer.crend();
    }
};

