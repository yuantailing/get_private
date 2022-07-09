#pragma once

#define DEFINE_GET_PRIVATE(ret_type, func_name, ret_val)  \
namespace detail_##func_name {  \
using RetType = ret_type;  \
template<typename T, T p>  \
struct Tunnel {  \
    friend inline RetType func_name() { return p; }  \
};  \
template struct Tunnel<RetType, ret_val>;  \
inline RetType func_name();  \
}  \
using detail_##func_name::func_name;