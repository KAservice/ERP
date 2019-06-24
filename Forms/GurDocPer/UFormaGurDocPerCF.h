#ifndef UFormaGurDocPerCFH                  
#define UFormaGurDocPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurDocPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurDocPerCF();                                                           
   ~TFormaGurDocPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
