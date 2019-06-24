#ifndef UREM_DMCustQueryCFH                  
#define UREM_DMCustQueryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMCustQueryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMCustQueryCF();                                                           
   ~TREM_DMCustQueryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
