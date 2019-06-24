#ifndef UDMDocRegKassaCFH                  
#define UDMDocRegKassaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRegKassaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRegKassaCF();                                                           
   ~TDMDocRegKassaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
