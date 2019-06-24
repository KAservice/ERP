#ifndef UREM_DMSprSostCustQueryCFH                  
#define UREM_DMSprSostCustQueryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprSostCustQueryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprSostCustQueryCF();                                                           
   ~TREM_DMSprSostCustQueryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
