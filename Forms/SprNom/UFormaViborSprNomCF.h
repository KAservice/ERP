#ifndef UFormaViborSprNomCFH                  
#define UFormaViborSprNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaViborSprNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaViborSprNomCF();                                                           
   ~TFormaViborSprNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
