#include "sampler.hpp"

void Sampler::create()
{
    glCreateSamplers(1, &_handle);
}

void Sampler::destroy()
{
    assert(glIsSampler(_handle));

    glDeleteSamplers(1, &_handle);
}

void Sampler::parameter(uint32_t param, int32_t value) const
{
    glSamplerParameteri(_handle, param, value);
}

void Sampler::bind_at_location(int32_t index) const
{
    glBindSampler(index, _handle);
}
