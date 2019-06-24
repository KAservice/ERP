#ifndef UFormaDocRegVsRaschCFH                  
#define UFormaDocRegVsRaschCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegVsRaschCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegVsRaschCF();                                                           
   ~TFormaDocRegVsRaschCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
