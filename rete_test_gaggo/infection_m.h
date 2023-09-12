//
// Generated file, do not edit! Created by opp_msgtool 6.0 from infection.msg.
//

#ifndef __INFECTION_M_H
#define __INFECTION_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class Infection;
/**
 * Class generated from <tt>infection.msg:2</tt> by opp_msgtool.
 * <pre>
 * message Infection
 * {
 *     int maxInfectable;
 *     int numInfected;
 * }
 * </pre>
 */
class Infection : public ::omnetpp::cMessage
{
  protected:
    int maxInfectable = 0;
    int numInfected = 0;

  private:
    void copy(const Infection& other);

  protected:
    bool operator==(const Infection&) = delete;

  public:
    Infection(const char *name=nullptr, short kind=0);
    Infection(const Infection& other);
    virtual ~Infection();
    Infection& operator=(const Infection& other);
    virtual Infection *dup() const override {return new Infection(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getMaxInfectable() const;
    virtual void setMaxInfectable(int maxInfectable);

    virtual int getNumInfected() const;
    virtual void setNumInfected(int numInfected);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Infection& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Infection& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline Infection *fromAnyPtr(any_ptr ptr) { return check_and_cast<Infection*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INFECTION_M_H
