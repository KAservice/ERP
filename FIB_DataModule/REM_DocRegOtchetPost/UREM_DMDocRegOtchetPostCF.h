#ifndef UREM_DMDocRegOtchetPostCFH                  
#define UREM_DMDocRegOtchetPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocRegOtchetPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocRegOtchetPostCF();                                                           
   ~TREM_DMDocRegOtchetPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
