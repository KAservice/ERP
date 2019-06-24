#ifndef UREM_DMDocZOperCFH                  
#define UREM_DMDocZOperCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZOperCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZOperCF();                                                           
   ~TREM_DMDocZOperCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
