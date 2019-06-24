#ifndef UDMSprRaschSchetCFH                  
#define UDMSprRaschSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprRaschSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprRaschSchetCF();                                                           
   ~TDMSprRaschSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
