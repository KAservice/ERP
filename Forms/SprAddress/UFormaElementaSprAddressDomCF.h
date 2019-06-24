#ifndef UFormaElementaSprAddressDomCFH                  
#define UFormaElementaSprAddressDomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprAddressDomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprAddressDomCF();                                                           
   ~TFormaElementaSprAddressDomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
