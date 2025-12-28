// (csmith): For things like threads, I'd like to have a base "descriptor" structure.. maybe?
//           Something that says "This is what this is for, this is what to do on crashdump, this is how to present this object to the debugger", etc.
//           But right now, it'd only apply to threads. I'd like to revisit this in the future. Bikeshedding and all that.
#pragma once


class RThread {
public:
    RThread() = default;
    virtual ~RThread() = default;

    virtual void Start() = 0;
    virtual void Join()  = 0;
};