#ifndef UREM_DMSprSostCFH                  
#define UREM_DMSprSostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprSostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprSostCF();                                                           
   ~TREM_DMSprSostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
