#ifndef UREM_DMDocZPerCFH                  
#define UREM_DMDocZPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZPerCF();                                                           
   ~TREM_DMDocZPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
