#ifndef UFormaDocRegKassaCFH                  
#define UFormaDocRegKassaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegKassaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegKassaCF();                                                           
   ~TFormaDocRegKassaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
