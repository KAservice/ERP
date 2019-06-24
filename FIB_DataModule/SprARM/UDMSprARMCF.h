#ifndef UDMSprARMCFH                  
#define UDMSprARMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprARMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprARMCF();                                                           
   ~TDMSprARMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
