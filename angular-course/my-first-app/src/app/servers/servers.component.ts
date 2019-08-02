import { Component, OnInit } from "@angular/core";

@Component({
  selector: "app-servers",
  templateUrl: "./servers.component.html",
  styleUrls: ["./servers.component.css"]
})
export class ServersComponent implements OnInit {
  allowNewServer: boolean = false;
  serverCreationStatus = "No server was created!";
  serverName: string = "";
  duplicateServerName: string = "INITIAL VALUE";
  serverCreated: boolean = false;
  servers: string[] = ["Testserver", "Testserver 2"];
  username: string = "";
  display: boolean = false;
  displayClickCounter: number = 0;
  // displayClicks: number[] = [];
  displayClicks: Date[] = [];

  constructor() {
    setTimeout(() => {
      this.allowNewServer = true;
    }, 2000);
  }

  ngOnInit() {}

  onCreateServer() {
    this.serverCreated = true;
    this.servers.push(this.serverName);
    this.serverCreationStatus =
      "Server was created! Name is " + this.serverName;
  }

  onUpdateServerName(event: any) {
    // console.log(event);
    this.serverName = event.target.value;
  }

  onResetUsername() {
    this.username = "";
  }

  toggleDisplay() {
    this.display = !this.display;
    // this.displayClicks.push(this.displayClickCounter);
    // this.displayClickCounter = this.displayClickCounter + 1;
    this.displayClicks.push(new Date());
  }
}
