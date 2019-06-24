#ifndef UREM_DMSprKKTDvCFH                  
#define UREM_DMSprKKTDvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprKKTDvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprKKTDvCF();                                                           
   ~TREM_DMSprKKTDvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
