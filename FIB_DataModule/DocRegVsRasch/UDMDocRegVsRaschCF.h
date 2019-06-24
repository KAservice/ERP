#ifndef UDMDocRegVsRaschCFH                  
#define UDMDocRegVsRaschCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRegVsRaschCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRegVsRaschCF();                                                           
   ~TDMDocRegVsRaschCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
