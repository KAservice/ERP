#ifndef UDMDocPostNaSchetCFH                  
#define UDMDocPostNaSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocPostNaSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocPostNaSchetCF();                                                           
   ~TDMDocPostNaSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
