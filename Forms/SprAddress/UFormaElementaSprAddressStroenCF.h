#ifndef UFormaElementaSprAddressStroenCFH                  
#define UFormaElementaSprAddressStroenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprAddressStroenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprAddressStroenCF();                                                           
   ~TFormaElementaSprAddressStroenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
