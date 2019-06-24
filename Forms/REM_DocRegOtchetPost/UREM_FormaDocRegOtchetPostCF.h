#ifndef UREM_FormaDocRegOtchetPostCFH                  
#define UREM_FormaDocRegOtchetPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocRegOtchetPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocRegOtchetPostCF();                                                           
   ~TREM_FormaDocRegOtchetPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
