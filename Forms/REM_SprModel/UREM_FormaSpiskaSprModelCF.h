#ifndef UREM_FormaSpiskaSprModelCFH                  
#define UREM_FormaSpiskaSprModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprModelCF();                                                           
   ~TREM_FormaSpiskaSprModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
