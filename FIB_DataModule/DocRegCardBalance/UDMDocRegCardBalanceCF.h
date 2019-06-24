#ifndef UDMDocRegCardBalanceCFH                  
#define UDMDocRegCardBalanceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRegCardBalanceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRegCardBalanceCF();                                                           
   ~TDMDocRegCardBalanceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
