#ifndef UREM_FormaElementaSprSostCustQueryCFH                  
#define UREM_FormaElementaSprSostCustQueryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprSostCustQueryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprSostCustQueryCF();                                                           
   ~TREM_FormaElementaSprSostCustQueryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
