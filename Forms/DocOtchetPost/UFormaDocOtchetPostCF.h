#ifndef UFormaDocOtchetPostCFH                  
#define UFormaDocOtchetPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocOtchetPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocOtchetPostCF();                                                           
   ~TFormaDocOtchetPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
