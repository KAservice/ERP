#ifndef UDMSprNacenkaCFH                  
#define UDMSprNacenkaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNacenkaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNacenkaCF();                                                           
   ~TDMSprNacenkaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
