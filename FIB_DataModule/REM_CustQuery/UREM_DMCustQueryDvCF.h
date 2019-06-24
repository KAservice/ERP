#ifndef UREM_DMCustQueryDvCFH                  
#define UREM_DMCustQueryDvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMCustQueryDvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMCustQueryDvCF();                                                           
   ~TREM_DMCustQueryDvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
