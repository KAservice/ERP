#ifndef UREM_FormaDocVZipPerCFH                  
#define UREM_FormaDocVZipPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVZipPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVZipPerCF();                                                           
   ~TREM_FormaDocVZipPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
