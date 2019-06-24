#ifndef UDMSprScaleCFH                  
#define UDMSprScaleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprScaleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprScaleCF();                                                           
   ~TDMSprScaleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
