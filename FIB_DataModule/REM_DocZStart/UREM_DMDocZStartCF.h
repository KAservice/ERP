#ifndef UREM_DMDocZStartCFH                  
#define UREM_DMDocZStartCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZStartCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZStartCF();                                                           
   ~TREM_DMDocZStartCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
