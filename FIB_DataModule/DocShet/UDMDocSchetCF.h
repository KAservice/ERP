#ifndef UDMDocSchetCFH                  
#define UDMDocSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocSchetCF();                                                           
   ~TDMDocSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
