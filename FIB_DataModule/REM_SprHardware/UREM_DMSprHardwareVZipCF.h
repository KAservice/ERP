#ifndef UREM_DMSprHardwareVZipCFH                  
#define UREM_DMSprHardwareVZipCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprHardwareVZipCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprHardwareVZipCF();                                                           
   ~TREM_DMSprHardwareVZipCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
