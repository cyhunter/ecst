// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <vrm/core/type_aliases.hpp>
#include <vrm/core/experimental/sparse_set.hpp>
#include <ecst/config.hpp>
#include <ecst/aliases.hpp>
#include <ecst/settings.hpp>
#include <ecst/context/types.hpp>

#include <iostream>

ECST_NAMESPACE
{
    template <sz_t TCapacity>
    using fixed_set = vrmc::fixed_vector_sparse_set<entity_id, TCapacity>;

    using dynamic_set = vrmc::dynamic_vector_sparse_set<entity_id>;

    namespace impl
    {
        template <typename TSettings>
        auto dispatch_set_type() noexcept
        {
            return static_if(settings::has_fixed_entity_storage<TSettings>)
                .then([](auto ts)
                    {
                        auto capacity = settings::fixed_capacity(ts);
                        return mp::type_c<fixed_set<decltype(capacity){}>>;
                    })
                .else_([](auto)
                    {
                        return mp::type_c<dynamic_set>;
                    })(TSettings{});
        }

        template <typename TSettings>
        using dispatch_set =
            mp::unwrap<decltype(dispatch_set_type<TSettings>())>;
    }

    using impl::dispatch_set;

    template <typename TSet, typename T>
    void add_range_in_set_reverse(TSet & set, T i_begin, T i_end)
    {
        // TODO: pattern for reverse loop and search in other projs
        if(i_end - i_begin == 0) return;

        for(T i(i_end - 1); i > i_begin; --i)
        {
            set.unchecked_add(i);
        }

        set.unchecked_add(i_begin);
    }

    template <typename TSet, typename T>
    void add_range_in_set_forward(TSet & set, T i_begin, T i_end)
    {
        for(T i(i_begin); i < i_end; ++i)
        {
            set.unchecked_add(i);
        }
    }
}
ECST_NAMESPACE_END
