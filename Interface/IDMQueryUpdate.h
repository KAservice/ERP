#ifndef UIDMQueryUpdateH
#define UIDMQueryUpdateH

#include "IDMFibConnection.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>


class __declspec(uuid("{226C4302-357A-41B6-8113-24C79D22F7B8}")) IDMQueryUpdate : public IMainInterface
{
public:
   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBTransaction * pFIBTr = {read = get_pFIBTr , write = set_pFIBTr};
   virtual TpFIBTransaction * get_pFIBTr(void)=0;
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr)=0;

};
#define IID_IDMQueryUpdate __uuidof(IDMQueryUpdate)
#endif
