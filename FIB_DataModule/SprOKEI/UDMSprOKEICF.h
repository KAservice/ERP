#ifndef UDMSprOKEICFH                  
#define UDMSprOKEICFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprOKEICF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprOKEICF();                                                           
   ~TDMSprOKEICF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
