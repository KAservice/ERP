#ifndef UDMDocPerCFH                  
#define UDMDocPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocPerCF();                                                           
   ~TDMDocPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
