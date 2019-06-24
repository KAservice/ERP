#ifndef UFormaElementaSprAddressNasPunktCFH                  
#define UFormaElementaSprAddressNasPunktCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprAddressNasPunktCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprAddressNasPunktCF();                                                           
   ~TFormaElementaSprAddressNasPunktCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
