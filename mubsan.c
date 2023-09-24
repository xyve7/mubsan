#include <stdint.h>

extern int mubsan_log(const char* format, ...);

const char* const mubsan_type_check_kinds[] = {
    "load of",
    "store to",
    "reference binding to",
    "member access within",
    "member call on",
    "constructor call on",
    "downcast of",
    "downcast of",
    "upcast of",
    "cast to virtual base of",
    "_Nonnull binding to",
    "dynamic operation on"};

typedef struct {
    const char* file;
    uint32_t line;
    uint32_t col;
} mubsan_source_location;

typedef struct {
    uint16_t kind;
    uint16_t info;
    char name[];
} mubsan_type_description;

typedef struct {
    mubsan_source_location loc;
    mubsan_type_description* type;
    uint8_t alignment;
    uint8_t check_kind;
} mubsan_type_mismatch_info_v1;

typedef struct {
    mubsan_source_location loc;
    mubsan_type_description* type;
} mubsan_overflow;

typedef struct {
    mubsan_source_location loc;
} mubsan_pointer_overflow;

typedef struct {
    mubsan_source_location loc;
    mubsan_type_description* array_type;
    mubsan_type_description* index_type;
} mubsan_out_of_bounds;
void __ubsan_handle_type_mismatch_v1(mubsan_type_mismatch_info_v1* data, uintptr_t ptr) {
    const char* reason = "type mismatch";

    if (ptr == 0) {
        reason = "dereference of a NULL pointer";
    } else if (data->alignment && (ptr & (data->alignment - 1))) {
        reason = "use of a misaligned pointer";
    }

    mubsan_log("mubsan: %s in %s, line %u, column %u, %s %s at alignment %u at address 0x%lx\n",
               reason,
               data->loc.file,
               data->loc.line,
               data->loc.col,
               mubsan_type_check_kinds[data->check_kind],
               data->type->name,
               data->alignment,
               ptr);
}
void __ubsan_handle_add_overflow(mubsan_overflow* data, uintptr_t lhs, uintptr_t rhs) {
    mubsan_log("mubsan: addition overflow in %s, line %u, column %u, %s %lu + %lu\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               data->type->name,
               lhs,
               rhs);
}
void __ubsan_handle_sub_overflow(mubsan_overflow* data, uintptr_t lhs, uintptr_t rhs) {
    mubsan_log("mubsan: subtraction overflow in %s, line %u, column %u, %s %lu - %lu\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               data->type->name,
               lhs,
               rhs);
}
void __ubsan_handle_mul_overflow(mubsan_overflow* data, uintptr_t lhs, uintptr_t rhs) {
    mubsan_log("mubsan: multiplication overflow in %s, line %u, column %u, %s %lu * %lu\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               data->type->name,
               lhs,
               rhs);
}
void __ubsan_handle_negate_overflow(mubsan_overflow* data, uintptr_t val) {
    mubsan_log("mubsan: addition overflow in %s, line %u, column %u, %s %lu\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               data->type->name,
               val);
}
void __ubsan_handle_divrem_overflow(mubsan_overflow* data, uintptr_t lhs, uintptr_t rhs) {
    mubsan_log("mubsan: division overflow in %s, line %u, column %u, %s %lu / %lu\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               data->type->name,
               lhs,
               rhs);
}
void __ubsan_handle_pointer_overflow(mubsan_pointer_overflow* data, uintptr_t base, uintptr_t result) {
    mubsan_log("mubsan: pointer overflow in %s, line %u, column %u, base=0x%lx, result=0x%lx\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               base,
               result);
}
void __ubsan_handle_out_of_bounds(mubsan_out_of_bounds* data, uintptr_t index) {
    mubsan_log("mubsan: array out of bounds in %s, line %u, column %u, %s at %s %lu\n",
               data->loc.file,
               data->loc.line,
               data->loc.col,
               data->array_type->name,
               data->index_type->name,
               index);
}
