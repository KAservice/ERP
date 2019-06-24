#ifndef UREM_DMDocZAktPrCFH                  
#define UREM_DMDocZAktPrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZAktPrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZAktPrCF();                                                           
   ~TREM_DMDocZAktPrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
