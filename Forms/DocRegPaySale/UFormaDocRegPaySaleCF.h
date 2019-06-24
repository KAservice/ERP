#ifndef UFormaDocRegPaySaleCFH                  
#define UFormaDocRegPaySaleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegPaySaleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegPaySaleCF();                                                           
   ~TFormaDocRegPaySaleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
