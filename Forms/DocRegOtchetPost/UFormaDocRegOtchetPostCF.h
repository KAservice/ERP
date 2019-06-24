#ifndef UFormaDocRegOtchetPostCFH                  
#define UFormaDocRegOtchetPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegOtchetPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegOtchetPostCF();                                                           
   ~TFormaDocRegOtchetPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
