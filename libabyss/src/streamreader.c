#include "streamreader.h"
#include <stdlib.h>
#include <string.h>

typedef struct streamreader {
    const char* data;
    uint64_t data_size;
    uint64_t position;
} streamreader;

streamreader * streamreader_create(const void* data, const uint64_t data_size) {
    streamreader *result = malloc(sizeof(streamreader));
    
    result->data = (char*)data;
    result->position = 0;
    result->data_size = data_size;
    
    return result;
}

void streamreader_destroy(streamreader *source) {
    free(source);
}

uint8_t streamreader_read_byte(streamreader *source) {
    return source->data[source->position++];
}

int16_t streamreader_read_int16(streamreader *source) {
    return(int16_t)streamreader_read_uint16(source);
}

uint16_t streamreader_read_uint16(streamreader *source) {
    uint8_t value[2];
    streamreader_get_bytes(source, value, 2);
    return ((uint16_t)value[0]) | (((uint16_t)value[1]) << 8);
}

int32_t streamreader_read_int32(streamreader *source) {
    return (int32_t)streamreader_read_uint32(source);
}

uint32_t streamreader_read_uint32(streamreader *source) {
    uint8_t value[4];
    streamreader_get_bytes(source, value, 4);
    return ((uint32_t)value[0]) | (((uint32_t)value[1]) << 8) | (((uint32_t)value[2]) << 16) | (((uint32_t)value[3]) << 24);
}

int64_t streamreader_read_int64(streamreader *source) {
    return (int64_t)streamreader_read_uint64(source);
}

uint64_t streamreader_read_uint64(streamreader *source) {
    uint8_t value[8];
    streamreader_get_bytes(source, value, 8);
    return ((uint64_t)value[0]) | (((uint64_t)value[1]) << 8) | (((uint64_t)value[2]) << 16) | (((uint64_t)value[3]) << 24)
    | (((uint64_t)value[3]) << 32) | (((uint64_t)value[3]) << 40) | (((uint64_t)value[3]) << 48) | (((uint64_t)value[3]) << 56);
}

uint64_t streamreader_get_position(const streamreader *source) {
    return source->position;
}

void streamreader_set_position(streamreader *source, uint64_t position) {
    source->position = position;
}

void streamreader_get_bytes(streamreader *source, void* buffer, const uint64_t count) {
    memcpy(buffer, source->data, count);
    source->position += count;
}

void streamreader_skip_bytes(streamreader *source, const uint64_t count) {
    source->position += count;
}

bool streamreader_eof(const streamreader *source) {
    return source->position >= source->data_size;
}

