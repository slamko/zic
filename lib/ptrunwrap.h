/* This file is part of Zic project.

Zic is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

Zic is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
Zic. If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef ZIC_PTR_UNWRAP
#define ZIC_PTR_UNWRAP


#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
#warning Some macro wrappers may not be available for MSVC. Specify /Zc:preprocessor option to enable full macro-feature set
#else
#undef ZIC_ENABLE_LABEL_OVERLOADING
#define ZIC_ENABLE_LABEL_OVERLOADING
#endif

#define ZIC_PTR_UNWRAP_VAR_NAME ZIC_unwrap_ptr_res

#define ZIC_PTR_UNWRAP_INIT() void *ZIC_unwrap_ptr_res = NULL;

#define PTR_UNWRAP_CLEANUP(EXP) \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_CLEANUP(ERR_SYS) } }

#define PTR_UNWRAP_FINAL(EXP) \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_FINAL(ERR_SYS) } }

#define PTR_UNWRAP_LABEL(EXP, LABEL) \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_LABEL(ERR_SYS, LABEL) } }

#define PTR_UNWRAP_ERR_CLEANUP(EXP, ERR) { \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_CLEANUP(ERR) } }

#define PTR_UNWRAP_ERR_FINAL(EXP, ERR) { \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_FINAL(ERR) } }

#define PTR_UNWRAP_ERR_LABEL(EXP, LABEL, ERR) { \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_LABEL(ERR, LABEL) } }

#define PTR_UNWRAP_LOCAL_CLEANUP(EXP) PTR_UNWRAP_ERR_CLEANUP(EXP, ERR_LOCAL)

#define PTR_UNWRAP_USER_CLEANUP(EXP) PTR_UNWRAP_ERR_CLEANUP(EXP, ERR_USER)

#define PTR_UNWRAP(EXP) PTR_UNWRAP_FINAL(EXP)

#define PTR_UNWRAP_SYS(EXP) PTR_UNWRAP_FINAL(EXP)

#define PTR_UNWRAP_ERR(EXP, ERR) PTR_UNWRAP_ERR_FINAL(EXP, ERR)

#define PTR_UNWRAP_LOCAL(EXP) PTR_UNWRAP_ERR_FINAL(EXP, ERR_LOCAL)

#define PTR_UNWRAP_USER(EXP) PTR_UNWRAP_ERR_FINAL(EXP, ERR_USER)

#define OR(EXP) \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME

#define ELSE_PTR(EXP) : (EXP) ;

#ifndef ZIC_DEFER

#undef DEF

#define DEF { \
    ZIC_RESULT_INIT() \
    ZIC_PTR_UNWRAP_INIT()

#endif

#endif // ZIC_PTR_UNWRAP
