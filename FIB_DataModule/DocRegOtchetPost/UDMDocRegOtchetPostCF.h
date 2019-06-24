#ifndef UDMDocRegOtchetPostCFH                  
#define UDMDocRegOtchetPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRegOtchetPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRegOtchetPostCF();                                                           
   ~TDMDocRegOtchetPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
