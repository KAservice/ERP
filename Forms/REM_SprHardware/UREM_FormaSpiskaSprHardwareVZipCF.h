#ifndef UREM_FormaSpiskaSprHardwareVZipCFH                  
#define UREM_FormaSpiskaSprHardwareVZipCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprHardwareVZipCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprHardwareVZipCF();                                                           
   ~TREM_FormaSpiskaSprHardwareVZipCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
