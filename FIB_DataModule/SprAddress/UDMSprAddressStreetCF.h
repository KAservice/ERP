#ifndef UDMSprAddressStreetCFH                  
#define UDMSprAddressStreetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressStreetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressStreetCF();                                                           
   ~TDMSprAddressStreetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
