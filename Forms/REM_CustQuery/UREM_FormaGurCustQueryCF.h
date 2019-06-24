#ifndef UREM_FormaGurCustQueryCFH                  
#define UREM_FormaGurCustQueryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurCustQueryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurCustQueryCF();                                                           
   ~TREM_FormaGurCustQueryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
