#ifndef UFormaElementaSprAddressStreetCFH                  
#define UFormaElementaSprAddressStreetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprAddressStreetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprAddressStreetCF();                                                           
   ~TFormaElementaSprAddressStreetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
