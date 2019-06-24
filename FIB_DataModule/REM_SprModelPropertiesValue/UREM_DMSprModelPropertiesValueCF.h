#ifndef UREM_DMSprModelPropertiesValueCFH                  
#define UREM_DMSprModelPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprModelPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprModelPropertiesValueCF();                                                           
   ~TREM_DMSprModelPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
