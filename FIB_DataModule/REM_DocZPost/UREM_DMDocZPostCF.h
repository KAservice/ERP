#ifndef UREM_DMDocZPostCFH                  
#define UREM_DMDocZPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZPostCF();                                                           
   ~TREM_DMDocZPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
